IMAGE_NAME := asciidoxy-builder

--check-%:
	@if [ "`command -v ${*}`" = "" ]; then \
		echo "Command ${*} not found in path";  \
		exit 1; \
	fi

--guard-%:
	@if [ "${${*}}" = "" ]; then \
		echo "Environment variable $* not set: $*=abc123 make $(MAKECMDGOALS)"; \
		exit 1; \
	fi

build: --check-podman
	podman build -t $(IMAGE_NAME) -f Containerfile

docker-push: --check-podman --guard-VERSION build
	podman login docker.io
	podman push $(IMAGE_NAME):latest docker.io/$(USER)/$(IMAGE_NAME):$(VERSION)
