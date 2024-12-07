// Ref to wrapp cpp
// https://github.com/anagram3k/zig-with-cpp/tree/main?tab=readme-ov-file

const c = @cImport({
    @cInclude("entry_point.c");
});

pub fn main() !void {
    c.entry_point();
}
