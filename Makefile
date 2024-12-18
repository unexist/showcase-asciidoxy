MOUNTPATH := /asciidoxy
VERSION := 0.3

--check-%:
	@if [ "`command -v ${*}`" = "" ]; then \
		echo "Command ${*} not found in path";  \
		exit 1; \
	fi

git-submod:
	git submodule init
	git submodule update

hg.submod:
	hg up

doxygen: --check-podman
	podman run --rm -v $(CURDIR):$(MOUNTPATH) \
		-it docker.io/unexist/asciidoxy-builder:$(VERSION) \
		sh -c "cd $(MOUNTPATH) && doxygen"

doxygen-generate: --check-podman
	podman run --rm -v $(CURDIR):$(MOUNTPATH) \
		-it docker.io/unexist/asciidoxy-builder:$(VERSION) \
		sh -c "cd $(MOUNTPATH) && doxygen -g Doxyfile"

asciidoxy: --check-podman
	podman run --rm -v $(CURDIR):$(MOUNTPATH) \
		-it docker.io/unexist/asciidoxy-builder:$(VERSION) \
		sh -c "cd $(MOUNTPATH) && asciidoxy \
		--require asciidoctor-diagram \
		--spec-file packages.toml \
		--base-dir text \
		--destination-dir build \
		--build-dir build \
		-b adoc \
		text/index.adoc"

versions:
	podman run --rm -v $(CURDIR):$(MOUNTPATH) \
		-it docker.io/unexist/asciidoxy-builder:$(VERSION) \
		sh -c "cd $(MOUNTPATH) && doxygen --version"
	podman run --rm -v $(CURDIR):$(MOUNTPATH) \
		-it docker.io/unexist/asciidoxy-builder:$(VERSION) \
		sh -c "cd $(MOUNTPATH) && asciidoxy -h | grep -E '[0-9\.]{5}'"

clean:
	rm -rf doxygen/xml/*
	rm -rf build/*

docs: doxygen asciidoxy

open-doxygen: --check-open
	open doxygen/html/index.html

