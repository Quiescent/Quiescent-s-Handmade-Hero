with import <nixpkgs> {};
{
  testEnv = stdenv.mkDerivation {
    name = "handMade";
    buildInputs = with llvmPackages; [SDL2 gcc gdb clang-unwrapped];
  };
}