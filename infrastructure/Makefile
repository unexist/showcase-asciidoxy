IMAGE_NAME := cesentry-firmware-builder

--guard-%:
	@if [ "${${*}}" = "" ]; then \
		echo "Environment variable $* not set: $*=abc123 make $(MAKECMDGOALS)"; \
		exit 1; \
	fi

build:
	podman build -t $(IMAGE_NAME) -f Containerfile

docker-push: --guard-VERSION build
	podman login docker.io
	podman push $(IMAGE_NAME):latest docker.io/$(USER)/$(IMAGE_NAME):$(VERSION)

gitlab-push: --guard-REGISTRY_URL --guard-VERSION build
	podman login $(REGISTRY_URL)
	podman push --tls-verify=false  \
		$(IMAGE_NAME):latest $(REGISTRY_URL)/documentation/cesentry-firmware/$(IMAGE_NAME):$(VERSION)
