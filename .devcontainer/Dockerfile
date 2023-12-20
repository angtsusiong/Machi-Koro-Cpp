ARG VARIANT=ubuntu-22.04
FROM mcr.microsoft.com/devcontainers/base:${VARIANT}
USER root

ENV LANGUAGE="en_US.UTF-8" \
    LANG="en_US.UTF-8" \
    TERM="xterm" \
    HOME="/root" \
    CC=gcc-12 \
    CXX=g++-12 \
    AR=gcc-ar-12 \
    RANLIB=gcc-ranlib-12

RUN set -xe && \
    echo "**** install dependency ****" && \
    apt-get update && \
    apt-get install -y \
        apt-utils \
        build-essential \
        locales && \
    apt-get install -y \
        curl \
        wget \
        gnupg \
        cmake \
        cppcheck \
        make \
        git \
        gcc-12 \
        g++-12 \
        pkg-config \
        openssl \
        llvm-toolchain-15 \
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
        valgrind \
        vim \
        neovim \
        google-mock && \
    echo "**** generate locale ****" && \
    locale-gen en_US.UTF-8 && \
    echo "**** set gcc version ****" && \
    update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-12 100 && \
    update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-12 100 && \
    update-alternatives --install /usr/bin/llvm-config llvm-config /usr/bin/llvm-config-15 100 && \
    update-alternatives --install /usr/bin/lldb lldb /usr/bin/lldb-15 100 && \
    update-alternatives --install /usr/bin/lld lld /usr/bin/lld-15 100 && \
    update-alternatives --install /usr/bin/clang clang /usr/bin/clang-15 100 && \
    update-alternatives --install /usr/bin/clang-tools clang-tools /usr/bin/clang-tools-15 100 && \
    update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-15 100 && \
    update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-15 100 && \
    update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-15 100 && \
    echo "**** download sourcecode ****" && \
    git clone --recursive "https://github.com/drogonframework/drogon" "$HOME/drogon" && \
    cd "$HOME/drogon" && \
    mkdir build && \
    cd build && \
    cmake \
        -DCMAKE_BUILD_TYPE=RELEASE \
        -DCMAKE_INSTALL_PREFIX=/usr \
        .. && \
    echo "**** build sourcecode ****" && \
    make && \
    mkdir "$HOME/release" && \
    make DESTDIR="$HOME/release/" install && \
    echo "**** install drogon ****" && \
    cp -r "$HOME/release/usr" / && \
    cd "$HOME" && \
    apt-get autoremove -y && \
    apt-get clean -y && \
    rm -rf /var/lib/apt/lists/* && \
    rm -rf "$HOME/drogon" && \
    rm -rf "$HOME/release" && \
    timedatectl set-timezone Asia/Taipei
    
ARG USERNAME=vscode
