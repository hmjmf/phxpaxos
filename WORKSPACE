load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")


git_repository(
    name = "com_google_protobuf",
    remote = "https://github.com/protocolbuffers/protobuf.git",
    tag = "v3.25.1",
)
load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")
protobuf_deps()

git_repository(
    name = "com_google_leveldb",
    remote = "https://github.com/google/leveldb.git",
    tag = "v1.20",
    build_file = "//:build_files/leveldb.BUILD",
)

git_repository(
    name = "com_github_gflags_gflags",
    remote = "https://github.com/gflags/gflags.git",
    tag = "v2.2.2"
)

git_repository(
    name = "com_google_glog",
    remote = "https://github.com/google/glog.git",
    tag = "v0.6.0"
)
