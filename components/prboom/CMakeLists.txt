idf_component_register(SRCS "am_map.c" "f_finale.c" "lprintf.c" "mmus2mid.c" "p_lights.c" "p_sight.c" "r_demo.c" "r_sky.c" "version.c" "d_client.c"  "f_wipe.c" "m_argv.c" "p_ceilng.c" "p_map.c" "p_spec.c" "r_draw.c" "r_things.c" "w_mmap.c" "d_deh.c" "g_game.c" "m_bbox.c" "p_checksum.c" "p_maputl.c" "p_switch.c" "r_filter.c" "s_sound.c" "w_wad.c" "d_items.c" "gl_main.c" "m_cheat.c" "p_doors.c" "p_mobj.c" "p_telept.c" "r_fps.c" "sounds.c" "wi_stuff.c" "d_main.c" "gl_texture.c" "m_menu.c" "p_enemy.c" "p_plats.c" "p_tick.c" "r_main.c" "st_lib.c" "z_bmalloc.c" "doomdef.c" "hu_lib.c" "m_misc.c" "p_floor.c" "p_pspr.c" "p_user.c" "r_patch.c" "st_stuff.c"  "z_zone.c" "doomstat.c" "hu_stuff.c" "m_random.c" "p_genlin.c" "p_saveg.c" "r_bsp.c" "r_plane.c" "tables.c" "dstrings.c" "info.c" "md5.c" "p_inter.c" "p_setup.c" "r_data.c" "r_segs.c" "v_video.c"
                    INCLUDE_DIRS "include"
                    REQUIRES "prboom-wad-tables"
)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=char-subscripts" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=unused-value" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=parentheses" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=int-to-pointer-cast" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=pointer-sign" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=unused-but-set-variable" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=maybe-uninitialized" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=misleading-indentation" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=format-overflow" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=nonnull" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=unused-but-set-parameter" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=unused-const-variable" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=duplicate-decl-specifier" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=sizeof-pointer-div" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=dangling-else" APPEND)

#idf_build_set_property(COMPILE_OPTIONS "-Wno-error=misleading-indentation" APPEND)
#idf_build_set_property(COMPILE_OPTIONS "-Wno-error=unused-variable" APPEND)
#idf_build_set_property(COMPILE_OPTIONS "-Wno-error=unused-but-set-variable" APPEND)
#idf_build_set_property(COMPILE_OPTIONS "-Wno-error=format-overflow" APPEND)
#idf_build_set_property(COMPILE_OPTIONS "-Wno-error=nonnull" APPEND)
#idf_build_set_property(COMPILE_OPTIONS "-Wno-error=pointer-sign" APPEND)
#idf_build_set_property(COMPILE_OPTIONS "-Wno-error=maybe-uninitialized" APPEND)

