bazel clean
bazel build phxpaxos_test 

bazel-bin/phxpaxos_test 127.0.0.1:10086 127.0.0.1:10086,127.0.0.1:10087,127.0.0.1:10088 >>/dev/null &
bazel-bin/phxpaxos_test 127.0.0.1:10087 127.0.0.1:10086,127.0.0.1:10087,127.0.0.1:10088 >>/dev/null &
bazel-bin/phxpaxos_test 127.0.0.1:10087 127.0.0.1:10086,127.0.0.1:10087,127.0.0.1:10088 >>/dev/null &

bazel clean