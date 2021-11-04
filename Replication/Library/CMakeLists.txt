cmake_minimum_required(VERSION 3.19)

include(FetchContent)

FetchContent_Declare(
  UQACNetwork
  GIT_REPOSITORY https://gitlab.com/LucasDaCosta/exampletp1.git
  GIT_TAG main
)

FetchContent_MakeAvailable(UQACNetwork)