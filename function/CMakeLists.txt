SET(FUNCTION_SRCS Function.cpp Bind.cpp FunctionA.cpp FunctionB.cpp)
SET(FUNCTION_HEADERS include/Function.h include/Bind.h include/FunctionA.h include/FunctionB.h)
INCLUDE_DIRECTORIES(
        ${CStudyIncludes}
)
ADD_LIBRARY(function SHARED ${FUNCTION_HEADERS} ${FUNCTION_SRCS})
