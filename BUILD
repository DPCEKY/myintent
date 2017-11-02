cc_library(
    name = "myrpc",
    srcs = ["myrpc_types.cpp","myrpc_constants.cpp","HeapSort.cpp"],
    hdrs = ["myrpc_types.h","myrpc_constants.h","HeapSort.h"],
)

cc_binary(
    name = "sort",
    srcs = ["server.cpp"],
    copts = [
        "-I/usr/local/include/thrift",
        "-I/usr/local/include/boost",
        "-L/usr/local/lib",
    ],
 
    linkopts = ["-lthrift","-DHAVE_NETINET_IN_H"],
    deps = [":myrpc"],

)
