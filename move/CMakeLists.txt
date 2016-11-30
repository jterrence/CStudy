SET(MOVE_SRCS Move.cpp MoveA.cpp)
SET(MOVE_HEADERS include/Move.h include/MoveA.h)
INCLUDE_DIRECTORIES(
        ${CStudyIncludes}
)
ADD_LIBRARY(move SHARED ${MOVE_HEADERS} ${MOVE_SRCS})