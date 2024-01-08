ARG VARIANT="jammy"
FROM mcr.microsoft.com/devcontainers/base:${VARIANT}

ENV LANGUAGE="en_US.UTF-8" \
    LANG="en_US.UTF-8" \
    TERM="xterm-256color" \
    CC="gcc-12" \
    CXX="g++-12" \
    AR="gcc-ar-12" \
    RANLIB="gcc-ranlib-12"

RUN set -xe && \
    echo "==== Generating locale ====" && \
    locale-gen en_US.UTF-8 && \
    echo "==== Setting timezone ====" && \
    unlink /etc/localtime && \
    ln -snf /usr/share/zoneinfo/Asia/Taipei /etc/localtime && \
    echo "Asia/Taipei" > /etc/timezone && \
    echo "==== Installing dependency ====" && \
    apt-get update && \
    apt-get install -y \
        cmake \
        cppcheck \
        valgrind \
        make \
        ninja-build \
        gcc-12 \
        g++-12 \
        pkg-config \
        openssl \
        llvm-15 \
        lld-15 \
        lldb-15 \
        clang-15 \
        clang-format-15 \
        clang-tidy-15 \
        clangd-15 \
        clang-tools-15 \
        llvm-15-tools \
        libssl-dev \
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
        libgmock-dev \
        googletest-tools && \
    apt-get autoremove -y && \
    apt-get clean -y && \
    rm -rf /var/lib/apt/lists/* && \
    echo "==== Setting gcc clang version ====" && \
    update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-12 100 && \
    update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-12 100 && \
    update-alternatives --install /usr/bin/llvm-config llvm-config /usr/bin/llvm-config-15 100 && \
    update-alternatives --install /usr/bin/lldb lldb /usr/bin/lldb-15 100 && \
    update-alternatives --install /usr/bin/lld lld /usr/bin/lld-15 100 && \
    update-alternatives --install /usr/bin/clang clang /usr/bin/clang-15 100 && \
    update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-15 100 && \
    update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-15 100 && \
    update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-15 100 && \
    echo "==== Installing drogon from source ====" && \
    git clone "https://github.com/drogonframework/drogon" "/tmp/drogon" && \
    cd "/tmp/drogon" && \
    ./build.sh && \
    rm -rf "/tmp/drogon"

ARG USERNAME=vscode
