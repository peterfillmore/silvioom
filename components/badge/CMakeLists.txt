idf_component_register(SRCS "badge_eink.c" "badge_eink_dev.c" "badge_eink_fb.c" "badge_eink_lut.c" "badge_nvs.c" "badge_base.c" "badge.c" 
                    INCLUDE_DIRS "include"
                    REQUIRES spi_flash nvs_flash 
                    )
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=implicit-function-declaration" APPEND)

