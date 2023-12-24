ARG VARIANT="jammy"
FROM mcr.microsoft.com/devcontainers/base:${VARIANT}

ENV LANGUAGE="en_US.UTF-8" \
    LANG="en_US.UTF-8" \
    CC=gcc-12 \
    CXX=g++-12 \
    AR=gcc-ar-12 \
    RANLIB=gcc-ranlib-12

RUN set -xe && \
    echo "**** install dependency ****" && \
    apt-get update && \
    apt-get upgrade -y && \
    apt-get update && \
    apt-get install -y \
        apt-utils \
        build-essential \
        locales \
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
        doxygen \
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
    update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-15 100 && \
    update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-15 100 && \
    update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-15 100 && \
    echo "**** download sourcecode ****" && \
    git clone --recursive "https://github.com/drogonframework/drogon" "/tmp/drogon" && \
    cd "/tmp/drogon" && \
    mkdir build && \
    cd build && \
    cmake \
        -DCMAKE_BUILD_TYPE=RELEASE \
        -DCMAKE_INSTALL_PREFIX=/usr \
        .. && \
    echo "**** build sourcecode ****" && \
    make && \
    mkdir "/tmp/release" && \
    make DESTDIR="/tmp/release/" install && \
    echo "**** install drogon ****" && \
    cp -r "/tmp/release/usr" / && \
    cd "/" && \
    apt-get autoremove -y && \
    apt-get clean -y && \
    rm -rf /var/lib/apt/lists/* && \
    rm -rf "/tmp/drogon" && \
    rm -rf "/tmp/release" && \
    unlink /etc/localtime && \
    ln -s /usr/share/zoneinfo/Asia/Taipei /etc/localtime
    
ARG USERNAME=vscode
