SET(FUNCTION_SRCS Function.cpp Bind.cpp)
SET(FUNCTION_HEADERS include/Function.h include/Bind.h)
INCLUDE_DIRECTORIES(
        ${CStudyIncludes}
)
ADD_LIBRARY(function SHARED ${FUNCTION_HEADERS} ${FUNCTION_SRCS})
