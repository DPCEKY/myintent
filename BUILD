cc_library(
    name = "mylib",
    srcs = [
        "myrpc_types.cpp","myrpc_constants.cpp","HeapSort.cpp"
    ],
    hdrs = [
        "myrpc_types.h","myrpc_constants.h","HeapSort.h"
    ],
    copts = [
        "-I/usr/local/include/boost",
    ],
    linkopts = ["-L/usr/local/lib","-lthrift"],
)

cc_binary(
    name = "server",
    srcs = [
        "server.cpp"
    ],
    copts = [
        "-I/usr/local/include/boost",
    ],
    deps = [":mylib"],
    linkopts = ["-L/usr/local/lib","-lthrift"],
)

cc_binary(
    name = "client",
    srcs = [
        "client.cpp"
    ],
    copts = [
        "-I/usr/local/include/boost",
    ],
    deps = [":mylib"],
    linkopts = ["-L/usr/local/lib","-lthrift"],
)
