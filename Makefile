MOUNTPATH := /asciidoxy

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

doxygen: --check-docker
	docker run --rm -v .:$(MOUNTPATH) \
		-it silvester747/asciidoxy:latest \
		sh -c 'cd $(MOUNTPATH) && doxygen'

asciidoxy: --check-docker
	docker run --rm -v .:$(MOUNTPATH) \
		-it silvester747/asciidoxy:latest \
		sh -c 'cd $(MOUNTPATH) && asciidoxy \
		--spec-file packages.toml \
		--base-dir text \
		--destination-dir build \
		--build-dir build \
		-b adoc \
		text/index.adoc'

docs: doxygen asciidoxy

open-doxygen: --check-open
	open doxygen/html/index.html

