add_requires("vcpkg::arrayfire")
target("test")
    set_kind("binary")
    add_files("src/*.c")
add_packages("vcpkg::arrayfire")