FIRMWARE_ROOTFS_VER=3.9
FIRMWARE_BUILDS_VER=099
FIRMWARE_BUILDS_REV=$(shell git rev-parse --short --remotes=origin 2>/dev/null |uniq)
FIRMWARE_CUSTOM_REV=$(shell git rev-parse --short HEAD 2>/dev/null)
