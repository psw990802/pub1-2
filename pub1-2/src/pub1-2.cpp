#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include <memory>
#include <chrono>
int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node=std::make_shared<rclcpp::Node>("node_pub1_2");
    auto qos_profile=rclcpp::QoS(rclcpp::KeepLast(10));
    auto mypub=node->create_publisher<geometry_msgs::msg::Vector3>("topic_pub1_2", 
    qos_profile);
    geometry_msgs::msg::Vector3 V;
    rclcpp::WallRate loop_rate(1.0);
    while(rclcpp::ok())
    {
        std::cin >> V.x;
        std::cin >> V.y;
        std::cin >> V.z;
        RCLCPP_INFO(node->get_logger(), "Publish: %.3f, %.3f, %.3f", V.x,V.y,V.z);
        mypub->publish(V);
        //rclcpp::spin_some(node);
        loop_rate.sleep(); //반복주파수에서남은시간만큼sleep
    }
    rclcpp::shutdown();
    return 0;
}