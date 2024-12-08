const std = @import("std");

const cflags = &.{"-fno-sanitize=undefined"};

pub fn build(b: *std.Build) void {
    const exe = b.addExecutable(.{
        .name = "Pokemon_Demo",
        .root_source_file = b.path("./src/main.zig"),
        .target = b.host,
    });

    exe.linkSystemLibrary("c");
    exe.linkSystemLibrary("c++");
    exe.linkSystemLibrary("SDL2");
    exe.addIncludePath(b.path("src"));
    exe.addCSourceFile(.{ .file = b.path("src/main.cpp"), .flags = cflags });
    exe.addCSourceFile(.{ .file = b.path("src/player.cpp"), .flags = cflags });

    // exe.linkLibC();

    b.installArtifact(exe);
}
