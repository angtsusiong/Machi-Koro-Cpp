ARG VARIANT="dev-ubuntu-24.04"
FROM mcr.microsoft.com/devcontainers/cpp:${VARIANT}

ENV LANG="en_US.UTF-8" \
    TZ="Asia/Taipei" \
    TERM="xterm-256color"

ARG DROGON_VERSION

RUN set -xe && \
    echo "==== Setting locale ====" && \
    update-locale LANG=${LANG} && \
    echo "==== Setting timezone ====" && \
    unlink /etc/localtime && \
    ln -snf /usr/share/zoneinfo/${TZ} /etc/localtime && \
    echo ${TZ} > /etc/timezone

RUN echo "==== Installing dependency ====" && \
    apt-get update && \
    export DEBIAN_FRONTEND=noninteractive && \
    apt-get install -y \
        libssl-dev \
        lld-18 \
        lldb-18 \
        clang-18 \
        clang-format-18 \
        clang-tidy-18 \
        clangd-18 \
        clang-tools-18 \
        ninja-build \
        doxygen \
        graphviz \
        xdot \
        dia \
        llvm-18-dev \
        libc++-18-dev \
        libc++abi-18-dev \
        libjsoncpp-dev \
        uuid-dev \
        zlib1g-dev \
        libc-ares-dev \
        libpqxx-dev \
        libmariadb-dev \
        libsqlite3-dev \
        libspdlog-dev \
        libhiredis-dev \
        libyaml-cpp-dev \
        libbrotli-dev \
        libgtest-dev \
        libgmock-dev && \
    apt-get clean -y && \
    rm -rf /var/lib/apt/lists/*

RUN echo "==== update alternatives clang ====" && \
    update-alternatives --install /usr/bin/clang clang /usr/bin/clang-18 100 && \
    update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-18 100 && \
    update-alternatives --install /usr/bin/lld lld /usr/bin/lld-18 100 && \
    update-alternatives --install /usr/bin/lldb lldb /usr/bin/lldb-18 100 && \
    update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-18 100 && \
    update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-18 100 && \
    update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-18 100

COPY 010-drogon-build-cpp20-spdlog.patch /tmp/010-drogon-build-cpp20-spdlog.patch

RUN echo "==== Installing drogon from source ====" && \
    DROGON_VERSION=$(curl -s https://api.github.com/repos/drogonframework/drogon/releases/latest | jq -r '.tag_name') && \
    git clone "https://github.com/drogonframework/drogon" "/tmp/drogon" && \
    cd "/tmp/drogon" && \
    echo "==== Installing Drogon version: ${DROGON_VERSION} ====" && \
    git checkout ${DROGON_VERSION} && \
    patch -d "/tmp/drogon" -Np1 -i "/tmp/010-drogon-build-cpp20-spdlog.patch" && \
    ./build.sh && \
    rm -rf "/tmp/drogon" "/tmp/010-drogon-build-cpp20-spdlog.patch"

ARG USERNAME=vscode