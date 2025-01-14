cmake_minimum_required (VERSION 3.8)
project(template-app)

if (WIN32)
	add_definitions(
		-DND_PLATFORM_WINDOWS 
		-DND_DEBUG
	)
endif()

# Dependencies
set(DEPENDENCIES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dependencies)

set(NODENS_DIR ${DEPENDENCIES_DIR}/nodens-engine)

# TemplateApp Source files
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
file(GLOB_RECURSE SOURCE_FILES ${SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${SOURCE_DIR}/*.h)

# Nodens Engine
add_subdirectory(${NODENS_DIR})
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(${PROJECT_NAME} 
	PUBLIC 
		${SOURCE_DIR} 
		${NODENS_DIR}/include
)

target_link_libraries(${PROJECT_NAME} 
	PUBLIC 
		nodens-engine
)

# set TemplateApp.cpp as startup item
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})