#include "rclcpp/rclcpp.hpp"
#include "cpp_srvcli/srv/add_two_floats.hpp"

#include <memory>

void add(const std::shared_ptr<cpp_srvcli::srv::AddTwoFloats::Request> request,
          std::shared_ptr<cpp_srvcli::srv::AddTwoFloats::Response>      response)
{
  response->sum = request->a + request->b;
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %f" " b: %f",
                request->a, request->b);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%f]", response->sum);
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_two_ints_server");

  rclcpp::Service<cpp_srvcli::srv::AddTwoFloats>::SharedPtr service =
    node->create_service<cpp_srvcli::srv::AddTwoFloats>("add_two_ints", &add);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to add two ints.");

  rclcpp::spin(node);
  rclcpp::shutdown();
}