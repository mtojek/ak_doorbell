FROM --platform=linux/amd64 ubuntu:22.04

# Install dependencies
RUN apt-get update
RUN apt-get install -y \
    build-essential \
    cmake \
    git \
    pkg-config \
    libfreetype6-dev \
    libpng-dev \
    libjpeg-dev \
    libudev-dev \
    libinput-dev \
    bzip2

RUN dpkg --add-architecture i386
RUN apt-get update
RUN apt-get install -y \
    libstdc++6:i386 \
    lib32stdc++6 \
    libmpc-dev:i386 \
    zlib1g:i386

RUN apt-get clean

RUN ln -s /lib/x86_64-linux-gnu/libmpfr.so.6 /lib/x86_64-linux-gnu/libmpfr.so.4

# Install anyka gcc toolchain
RUN mkdir -p /opt/toolchain
COPY toolchain/arm-anykav500-linux-uclibcgnueabi_V1.0.05.tar.bz2 /opt/toolchain/
RUN tar -xjf /opt/toolchain/arm-anykav500-linux-uclibcgnueabi_V1.0.05.tar.bz2 -C /opt/toolchain && \
    rm /opt/toolchain/arm-anykav500-linux-uclibcgnueabi_V1.0.05.tar.bz2

ENV TOOLCHAIN_ROOT=/opt/toolchain/arm-anykav500-linux-uclibcgnueabi
ENV PATH="${TOOLCHAIN_ROOT}/bin:${PATH}"

# Set working directory where project will be mounted at runtime
WORKDIR /app

# Default command
CMD [ "bash" ]
