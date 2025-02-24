// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pkg_test_cpp_msg:action/DistTurtle.idl
// generated code does not contain a copyright notice

#ifndef PKG_TEST_CPP_MSG__ACTION__DETAIL__DIST_TURTLE__STRUCT_H_
#define PKG_TEST_CPP_MSG__ACTION__DETAIL__DIST_TURTLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/DistTurtle in the package pkg_test_cpp_msg.
typedef struct pkg_test_cpp_msg__action__DistTurtle_Goal
{
  float linear_x;
  float angular_z;
  float dist;
} pkg_test_cpp_msg__action__DistTurtle_Goal;

// Struct for a sequence of pkg_test_cpp_msg__action__DistTurtle_Goal.
typedef struct pkg_test_cpp_msg__action__DistTurtle_Goal__Sequence
{
  pkg_test_cpp_msg__action__DistTurtle_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pkg_test_cpp_msg__action__DistTurtle_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/DistTurtle in the package pkg_test_cpp_msg.
typedef struct pkg_test_cpp_msg__action__DistTurtle_Result
{
  float pos_x;
  float pos_y;
  float pos_theta;
  float result_dist;
} pkg_test_cpp_msg__action__DistTurtle_Result;

// Struct for a sequence of pkg_test_cpp_msg__action__DistTurtle_Result.
typedef struct pkg_test_cpp_msg__action__DistTurtle_Result__Sequence
{
  pkg_test_cpp_msg__action__DistTurtle_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pkg_test_cpp_msg__action__DistTurtle_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/DistTurtle in the package pkg_test_cpp_msg.
typedef struct pkg_test_cpp_msg__action__DistTurtle_Feedback
{
  float remined_dist;
} pkg_test_cpp_msg__action__DistTurtle_Feedback;

// Struct for a sequence of pkg_test_cpp_msg__action__DistTurtle_Feedback.
typedef struct pkg_test_cpp_msg__action__DistTurtle_Feedback__Sequence
{
  pkg_test_cpp_msg__action__DistTurtle_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pkg_test_cpp_msg__action__DistTurtle_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "pkg_test_cpp_msg/action/detail/dist_turtle__struct.h"

/// Struct defined in action/DistTurtle in the package pkg_test_cpp_msg.
typedef struct pkg_test_cpp_msg__action__DistTurtle_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  pkg_test_cpp_msg__action__DistTurtle_Goal goal;
} pkg_test_cpp_msg__action__DistTurtle_SendGoal_Request;

// Struct for a sequence of pkg_test_cpp_msg__action__DistTurtle_SendGoal_Request.
typedef struct pkg_test_cpp_msg__action__DistTurtle_SendGoal_Request__Sequence
{
  pkg_test_cpp_msg__action__DistTurtle_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pkg_test_cpp_msg__action__DistTurtle_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/DistTurtle in the package pkg_test_cpp_msg.
typedef struct pkg_test_cpp_msg__action__DistTurtle_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} pkg_test_cpp_msg__action__DistTurtle_SendGoal_Response;

// Struct for a sequence of pkg_test_cpp_msg__action__DistTurtle_SendGoal_Response.
typedef struct pkg_test_cpp_msg__action__DistTurtle_SendGoal_Response__Sequence
{
  pkg_test_cpp_msg__action__DistTurtle_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pkg_test_cpp_msg__action__DistTurtle_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/DistTurtle in the package pkg_test_cpp_msg.
typedef struct pkg_test_cpp_msg__action__DistTurtle_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} pkg_test_cpp_msg__action__DistTurtle_GetResult_Request;

// Struct for a sequence of pkg_test_cpp_msg__action__DistTurtle_GetResult_Request.
typedef struct pkg_test_cpp_msg__action__DistTurtle_GetResult_Request__Sequence
{
  pkg_test_cpp_msg__action__DistTurtle_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pkg_test_cpp_msg__action__DistTurtle_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "pkg_test_cpp_msg/action/detail/dist_turtle__struct.h"

/// Struct defined in action/DistTurtle in the package pkg_test_cpp_msg.
typedef struct pkg_test_cpp_msg__action__DistTurtle_GetResult_Response
{
  int8_t status;
  pkg_test_cpp_msg__action__DistTurtle_Result result;
} pkg_test_cpp_msg__action__DistTurtle_GetResult_Response;

// Struct for a sequence of pkg_test_cpp_msg__action__DistTurtle_GetResult_Response.
typedef struct pkg_test_cpp_msg__action__DistTurtle_GetResult_Response__Sequence
{
  pkg_test_cpp_msg__action__DistTurtle_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pkg_test_cpp_msg__action__DistTurtle_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "pkg_test_cpp_msg/action/detail/dist_turtle__struct.h"

/// Struct defined in action/DistTurtle in the package pkg_test_cpp_msg.
typedef struct pkg_test_cpp_msg__action__DistTurtle_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  pkg_test_cpp_msg__action__DistTurtle_Feedback feedback;
} pkg_test_cpp_msg__action__DistTurtle_FeedbackMessage;

// Struct for a sequence of pkg_test_cpp_msg__action__DistTurtle_FeedbackMessage.
typedef struct pkg_test_cpp_msg__action__DistTurtle_FeedbackMessage__Sequence
{
  pkg_test_cpp_msg__action__DistTurtle_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pkg_test_cpp_msg__action__DistTurtle_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PKG_TEST_CPP_MSG__ACTION__DETAIL__DIST_TURTLE__STRUCT_H_
