cmake_minimum_required(VERSION 2.8)

##
## CONFIG
##

project (cataclysm)

if (NOT CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE Debug)
endif ()
set (VERSION_MAJOR 0)
set (VERSION_MINOR 3)
set (USE_BOOST no)

set (PROJECT_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}-i18n)

if (NOT MSVC)
  set (CMAKE_C_FLAGS                  "")
  set (CMAKE_C_FLAGS_DEBUG            "-O0 -D_DEBUG -g")
  set (CMAKE_C_FLAGS_RELWITHDEBINFO   "-O2 -D_DEBUG -g")
  set (CMAKE_C_FLAGS_RELEASE          "-O4 -DNDEBUG")
  set (CMAKE_C_FLAGS_MINSIZEREL       "-Os -DNDEBUG")
  set (CMAKE_CXX_FLAGS                "")
  set (CMAKE_CXX_FLAGS_DEBUG          "-O0 -D_DEBUG -g")
  set (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -D_DEBUG -g")
  set (CMAKE_CXX_FLAGS_RELEASE        "-O4 -DNDEBUG")
  set (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
endif ()

message (STATUS "${PROJECT_NAME} ${PROJECT_VERSION} (${CMAKE_BUILD_TYPE})")
set (CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install)

##
## MAIN
##

file (GLOB cataclysm_sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file (GLOB cataclysm_headers ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

if (WIN32)
  add_executable (${PROJECT_NAME} WIN32 ${cataclysm_sources})
else ()
  add_executable (${PROJECT_NAME} ${cataclysm_sources})
endif ()

install (FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}${CMAKE_EXECUTABLE_SUFFIX} DESTINATION .)

if (WIN32)
  target_link_libraries (${PROJECT_NAME} intl)
else ()
  target_link_libraries (${PROJECT_NAME} ncursesw)
endif()

add_custom_command (TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/data ${CMAKE_CURRENT_BINARY_DIR}/data
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/code_doc ${CMAKE_CURRENT_BINARY_DIR}/code_doc
  )
install (DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/data DESTINATION .)
install (DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/code_doc DESTINATION .)

add_definitions (-DPROJECT_NAME="${PROJECT_NAME}"
  -DPROJECT_VERSION="${PROJECT_VERSION}"
  )

set_target_properties (${PROJECT_NAME} PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION ${VERSION_MAJOR}
  )

if (MINGW)
  set_target_properties (${PROJECT_NAME} PROPERTIES
    LINK_FLAGS "${LINK_FLAGS} -static-libgcc -static-libstdc++"
    )
endif ()

if (USE_BOOST)
  find_package (Boost REQUIRED)
  set (Boost_USE_STATIC_LIBS    on)
  set (Boost_USE_MULTITHREADED  on)
  set (Boost_USE_STATIC_RUNTIME off)
  include_directories   (${Boost_INCLUDE_DIRS})
  link_directories      (${Boost_LIBRARY_DIRS})
  target_link_libraries (${target} ${Boost_LIBRARIES})
  add_definitions (-DUSE_BOOST)
endif ()

##
## LANGUAGES
##

set (lang_dir "lang")
add_definitions (-DLOCALEDIR="./${lang_dir}")

set (po_dir_path ${CMAKE_CURRENT_SOURCE_DIR}/${lang_dir})
set (mo_dir_path ${CMAKE_CURRENT_BINARY_DIR}/${lang_dir})

set (pot_target ${PROJECT_NAME}.pot)
set (pot_path ${po_dir_path}/${pot_target})

add_custom_target (po_dir_target
  COMMAND ${CMAKE_COMMAND} -E make_directory ${po_dir_path}
  )

set (XGETTEXT xgettext -k_ -kN_ -kP_:1,2 -F --force-po --add-comments=I18N:
  --package-name=${PROJECT_NAME} --package-version=${PROJECT_VERSION})
add_custom_target (xgettext ALL
  COMMAND ${XGETTEXT} -o ${pot_path} ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.h
  DEPENDS ${cataclysm_sources}
  DEPENDS ${cataclysm_headers}
  DEPENDS po_dir_target
  COMMENT "Generating ${pot_target}"
  )
install (FILES ${pot_path} DESTINATION ./lang)

add_custom_target (msgmerge
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/scripts/msgmerge.sh ${PROJECT_NAME} ${po_dir_path}
  DEPENDS xgettext
  )

add_custom_target (lang ALL
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/scripts/msgfmt.sh ${PROJECT_NAME} ${po_dir_path} ${mo_dir_path}
  DEPENDS msgmerge
  )
install (DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lang DESTINATION .)

