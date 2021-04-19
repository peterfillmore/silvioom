# Install script for directory: /Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Users/peterfillmore2/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mbedtls" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/aes.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/aesni.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/arc4.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/aria.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/asn1.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/asn1write.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/base64.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/bignum.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/blowfish.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/bn_mul.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/camellia.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ccm.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/certs.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/chacha20.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/chachapoly.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/check_config.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/cipher.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/cipher_internal.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/cmac.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/compat-1.3.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/config.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ctr_drbg.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/debug.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/des.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/dhm.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecdh.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecdsa.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecjpake.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecp.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecp_internal.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/entropy.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/entropy_poll.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/error.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/gcm.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/havege.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/hkdf.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/hmac_drbg.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md2.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md4.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md5.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md_internal.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/memory_buffer_alloc.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/net.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/net_sockets.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/nist_kw.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/oid.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/padlock.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pem.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pk.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pk_internal.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs11.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs12.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs5.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform_time.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform_util.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/poly1305.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ripemd160.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/rsa.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/rsa_internal.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha1.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha256.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha512.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_cache.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_ciphersuites.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_cookie.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_internal.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_ticket.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/threading.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/timing.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/version.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_crl.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_crt.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_csr.h"
    "/Users/peterfillmore2/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/xtea.h"
    )
endif()

