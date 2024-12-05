# Use a compatible base image for ARM64
FROM debian:bullseye-slim

# Avoid warnings by switching to noninteractive
ENV DEBIAN_FRONTEND=noninteractive

# Configure apt and install packages
RUN apt-get update \
    && apt-get -y install --no-install-recommends \
        build-essential \
        curl \
        git \
        python3 \
        python3-pip \
        nodejs \
        npm \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Install cross-compilation tools for Raspberry Pi
RUN apt-get update && apt-get install -y \
    gdb-multiarch \
    openssh-client \
    rsync \
    && rm -rf /var/lib/apt/lists/*

# Install CMake
RUN apt-get update && apt-get install -y cmake

# Create a non-root user
ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && apt-get update \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

# Set the default user
USER $USERNAME

# Set up Python environment
COPY requirements.txt /tmp/pip-tmp/
RUN pip3 install --user -r /tmp/pip-tmp/requirements.txt \
    && sudo rm -rf /tmp/pip-tmp

# Switch back to dialog for any ad-hoc use of apt-get
ENV DEBIAN_FRONTEND=dialog