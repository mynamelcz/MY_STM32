import os
import re
import json

DEFINES = ["-DUSE_STD_DRIVER", "-D__FPU_PRESENT"]

srcs = []
incdirs = []
flags = [
    "-c",
    "-fvisibility=hidden",
    "-O3",
    "-std=gnu11",
    "-nostartfiles",
    "--specs=nosys.specs",
    "-DNDEBUG",
]

# toolchain_home = os.path.abspath(
#     'D:/Andestech/AndeSight_STD_v511/toolchains/nds32le-elf-mculib-v5f/')
# sysincdirs = [
#     '-I%s' % os.path.join(toolchain_home, 'riscv32-elf/include'),
#     '-I%s' % os.path.join(toolchain_home, 'riscv32-elf/sys-include'),
#     '-I%s' %
#     os.path.join(toolchain_home, 'lib/gcc/riscv32-elf/10.3.0/include'),
#     '-I%s' %
#     os.path.join(toolchain_home, 'lib/gcc/riscv32-elf/10.3.0/include-fixed')
# ]
# toolchain = os.path.join(toolchain_home, 'bin/riscv32-elf-gcc.exe')
#

sysincdirs = [
    "-IF:/MDK5/ARM/ARMCC/include",
    "-IF:/MDK5/ARM/ARMCC/include/rw",
]

toolchain = "F:/MDK5/ARM/ARMCC/bin/armcc.exe"

project = os.path.abspath(".")
for root, dir, files in os.walk(project):
    for file in files:
        if re.search(r"\.c$|\.s$", file):
            print(os.path.join(root, file))
            srcs.append(os.path.join(root, file))
        if re.search(r"\.h$", file):
            inc = "-I%s" % root
            if inc not in incdirs:
                print(inc)
                incdirs.append(inc)

dump = []
args = []
args.append(toolchain)
args.extend(flags)
for tmp in DEFINES:
    args.append(tmp)
args.extend(sysincdirs)
args.extend(incdirs)
print(args)
for file in srcs:
    d = {}
    d["directory"] = project
    d_args = []
    d_args.extend(args)
    d_args.append("-o %s.o" % file)
    d_args.append(file)
    d["arguments"] = d_args
    d["file"] = file
    dump.append(d)

with open("compile_commands.json", "w") as f:
    json.dump(dump, f, indent=1)
    f.close()
