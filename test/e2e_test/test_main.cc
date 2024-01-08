#include <gtest/gtest.h>
#include <drogon/drogon.h>

#include <chrono>

int main(int argc, char** argv)
{
    std::promise<void> p1;
    auto f1 = p1.get_future();

    std::jthread thr([&p1] {
        drogon::app().getLoop()->queueInLoop([&p1] { p1.set_value(); });
        drogon::app().addListener("127.0.0.1", 8086).run();
    });

    f1.get();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    testing::InitGoogleTest(&argc, argv);
    int status = RUN_ALL_TESTS();

    drogon::app().getLoop()->queueInLoop([] { drogon::app().quit(); });
    return status;
}
