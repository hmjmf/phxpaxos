import os


def get_all_files(filepath):
  result = []
  files = os.listdir(filepath)
  for fi in files:
    path = os.path.join(filepath,fi)
    if os.path.isdir(path ):
      r = get_all_files(path)
      if r:
        result += r
    else:
      result.append(path)
  return result


all_files = get_all_files("src")

include_files = ["/".join(i.split("/")[1:]) for i in all_files if i[-1] == "h"]

skip = ["inttypes.h"]
force = {
  "master_sm.pb.h":"master/master_sm.pb.h",
  "paxos_msg.pb.h":"comm/paxos_msg.pb.h"
}


for f in all_files:
  ff = open(f)
  contnet = ff.read()
  head = [i.replace("#include \"", "").replace("\"", "").replace("\n", "") for i in contnet.split("\n") if "#include \"" in i]
  head = [i for i in head if i not in skip]
  for h in head:
    if len(h.split("/")) != 1:
      continue
    if h in force.keys():
      new_h = force[h]
    elif "/" not in h:
      new_h = include_files[[j.split("/")[-1] for j in include_files].index(h)]
    
    contnet = contnet.replace(f"\"{h}\"", f"\"{new_h}\"")
  ff = open(f, "w")
  ff.write(contnet)
  ff.close()



