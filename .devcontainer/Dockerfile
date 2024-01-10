ARG VARIANT="dev-debian"
FROM mcr.microsoft.com/devcontainers/cpp:${VARIANT}

ENV LANG="en_US.UTF-8" \
    TZ="Asia/Taipei" \
    TERM="xterm-256color"

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
        lld \
        clang-format \
        clang-tidy \
        clangd \
        clang-tools \
        doxygen \
        llvm-dev \
        libc++-dev \
        libjsoncpp-dev \
        uuid-dev \
        zlib1g-dev \
        libc-ares-dev \
        libpqxx-dev \
        libmariadb-dev \
        libsqlite3-dev \
        libhiredis-dev \
        libyaml-cpp-dev \
        libbrotli-dev \
        libgtest-dev \
        libgmock-dev && \
    apt-get autoremove -y && \
    apt-get clean -y && \
    rm -rf /var/lib/apt/lists/*

RUN echo "==== Installing drogon from source ====" && \
    git clone "https://github.com/drogonframework/drogon" "/tmp/drogon" && \
    cd "/tmp/drogon" && \
    ./build.sh && \
    rm -rf "/tmp/drogon"

ARG USERNAME=vscode