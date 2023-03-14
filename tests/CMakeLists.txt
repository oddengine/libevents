add_definitions("-DUT_ENABLED")

set(UT_SOURCES 
        ${EVENTS} 
        ${TOP_DIR}/tests/events/dummyeventtarget.cc 
        ${TOP_DIR}/tests/events/eventtarget_test.cc 
        ${TOP_DIR}/tests/main.cc 
)

add_executable(${PACKAGE_NAME}-ut ${UT_SOURCES})

set(UT_LIBRARIES gmock gtest ${LIBRARIES})

target_link_libraries(${PACKAGE_NAME}-ut ${UT_LIBRARIES})
