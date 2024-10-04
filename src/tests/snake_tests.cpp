#include <gtest/gtest.h>
#include "snake.h"

class SnakeTest : public ::testing::Test {
protected:
    void SetUp() override {
        app = new QApplication(argc, argv);
        snake = new Snake();
    }

    void TearDown() override {
        delete snake;
        delete app;
    }

    int argc = 0;
    char *argv[1] = {""};
    QApplication *app;
    Snake *snake;
};

TEST_F(SnakeTest, InitialState) {
    EXPECT_EQ(snake->getState(), Snake::GAME_INIT);
}

TEST_F(SnakeTest, StartGameChangesState) {
    snake->startGame();
    EXPECT_EQ(snake->getState(), Snake::GAME_RUN);
}

TEST_F(SnakeTest, MoveLeftUpdatesDirection) {
    snake->startGame();
    snake->moveLeft();
    EXPECT_EQ(snake->getDirection(), Snake::MOVE_LEFT);
}

TEST_F(SnakeTest, MoveRightUpdatesDirection) {
    snake->startGame();
    snake->moveRight();
    EXPECT_EQ(snake->getDirection(), Snake::MOVE_RIGHT);
}

TEST_F(SnakeTest, MoveUpUpdatesDirection) {
    snake->startGame();
    snake->moveUp();
    EXPECT_EQ(snake->getDirection(), Snake::MOVE_UP);
}

TEST_F(SnakeTest, MoveDownUpdatesDirection) {
    snake->startGame();
    snake->moveDown();
    EXPECT_EQ(snake->getDirection(), Snake::MOVE_DOWN);
}

TEST_F(SnakeTest, EvaluateTargetIncreasesCounter) {
    snake->startGame();
    snake->evalTarget();
    EXPECT_GT(snake->ui->labelCounter->text().toUInt(), 0);
}

TEST_F(SnakeTest, EvaluateGameDetectsSelfCollision) {
    snake->startGame();
    QPoint collisionPoint = snake->m_field.first(); 
    snake->evalGame(collisionPoint);
    EXPECT_EQ(snake->getState(), Snake::GAME_OVER);
}

TEST_F(SnakeTest, MoveLeftWrapsAroundField) {
    snake->startGame();
    snake->moveLeft(); 
    EXPECT_TRUE(snake->m_field.last().x() == m_width - Snake::m_step);
}

TEST_F(SnakeTest, KeyPressEventUpdatesDirection) {
    snake->startGame();
    QKeyEvent leftEvent(QEvent::KeyPress, Qt::Key_Left, Qt::NoModifier);
    snake->keyPressEvent(&leftEvent);
    EXPECT_EQ(snake->getDirection(), Snake::MOVE_LEFT);

    QKeyEvent upEvent(QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier);
    snake->keyPressEvent(&upEvent);
    EXPECT_EQ(snake->getDirection(), Snake::MOVE_UP);
}

TEST_F(SnakeTest, KeyPressEventStopsMovementOnSpace) {
    snake->startGame();
    QKeyEvent spaceEvent(QEvent::KeyPress, Qt::Key_Space, Qt::NoModifier);
    snake->keyPressEvent(&spaceEvent);
    EXPECT_EQ(snake->getDirection(), Snake::MOVE_NONE);
}

TEST_F(SnakeTest, KeyPressEventExitsOnEscape) {
    snake->startGame();
    QKeyEvent escapeEvent(QEvent::KeyPress, Qt::Key_Escape, Qt::NoModifier);
    snake->keyPressEvent(&escapeEvent);
    EXPECT_EQ(snake->getState(), Snake::GAME_EXIT);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
