{ pkgs }:

{
  deps = [
    pkgs.norminette     # ← the 42 checker
    pkgs.python311Full  # only if you still need python
  ];
}