install(
    TARGETS maze_exe
    RUNTIME COMPONENT maze_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
