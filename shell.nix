with import <nixpkgs> {};
{
  testEnv = stdenv.mkDerivation {
    name = "handMade";
    buildInputs = [SDL2];
  };
}