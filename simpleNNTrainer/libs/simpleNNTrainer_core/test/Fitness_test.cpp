#include "gtest/gtest.h"

#include "Fitness.h"


TEST( Fitness_test, Construction_Difference ) {
	Eigen::VectorXf diff = Eigen::VectorXf::Random(10);

	Fitness fit = Fitness( diff );
}

TEST( Fitness_test, Construction_Value_Expected ) {
	Eigen::VectorXf value = Eigen::VectorXf::Random( 10 );
	Eigen::VectorXf expected = Eigen::VectorXf::Random( 10 );

	Fitness fit = Fitness( value, expected );
}

TEST(Fitness_test, Construction_Value_Expected_negative) {
	Eigen::VectorXf value = Eigen::VectorXf::Random( 10 );
	Eigen::VectorXf expected = Eigen::VectorXf::Random( 9 );

	EXPECT_THROW(Fitness(value, expected), std::invalid_argument);
}

TEST( Fitness_test, Greater ) {
	Eigen::VectorXf diff = Eigen::VectorXf( 4 );
	diff[0] = 0.f;
	diff[1] = 0.f;
	diff[2] = 0.f;
	diff[3] = 0.f;

	Fitness fit = Fitness( diff );

	Eigen::VectorXf diffGreater = Eigen::VectorXf( 4 );
	diffGreater[0] = 0.f;
	diffGreater[1] = 0.f;
	diffGreater[2] = 1.f;
	diffGreater[3] = 0.f;

	Fitness fitGreater = Fitness( diffGreater );

	ASSERT_TRUE( fitGreater > fit );
	ASSERT_FALSE( fitGreater <= fit );
}

TEST( Fitness_test, GreaterOrEqual ) {
	Eigen::VectorXf diff = Eigen::VectorXf( 4 );
	diff[0] = 0.f;
	diff[1] = 0.f;
	diff[2] = 0.f;
	diff[3] = 0.f;

	Fitness fit = Fitness( diff );

	Eigen::VectorXf diffGreater = Eigen::VectorXf( 4 );
	diffGreater[0] = 0.f;
	diffGreater[1] = 0.f;
	diffGreater[2] = 0.f;
	diffGreater[3] = 0.f;

	Fitness fitGreater = Fitness( diffGreater );

	ASSERT_TRUE( fitGreater >= fit );
	ASSERT_FALSE( fitGreater < fit );
}

TEST( Fitness_test, Smaller ) {
	Eigen::VectorXf diff = Eigen::VectorXf( 4 );
	diff[0] = 1.f;
	diff[1] = 1.f;
	diff[2] = 1.f;
	diff[3] = 1.f;

	Fitness fit = Fitness( diff );

	Eigen::VectorXf diffSmaller = Eigen::VectorXf( 4 );
	diffSmaller[0] = 0.f;
	diffSmaller[1] = 0.f;
	diffSmaller[2] = 0.f;
	diffSmaller[3] = 0.f;

	Fitness fitSmaller = Fitness( diffSmaller );

	ASSERT_TRUE(fitSmaller < fit);
}

TEST( Fitness_test, SmallerOrEqual ) {
	Eigen::VectorXf diff = Eigen::VectorXf( 4 );
	diff[0] = 0.f;
	diff[1] = 0.f;
	diff[2] = 0.f;
	diff[3] = 0.f;

	Fitness fit = Fitness( diff );

	Eigen::VectorXf diffSmaller = Eigen::VectorXf( 4 );
	diffSmaller[0] = 0.f;
	diffSmaller[1] = 0.f;
	diffSmaller[2] = 0.f;
	diffSmaller[3] = 0.f;

	Fitness fitSmaller = Fitness( diffSmaller );

	ASSERT_TRUE( fitSmaller <= fit );
	ASSERT_FALSE( fitSmaller > fit );
}

TEST( Fitness_test, PositiveExpectedValue ) {
	Eigen::VectorXf value = Eigen::VectorXf( 4 );
	value[0] = 0.f;
	value[1] = 0.f;
	value[2] = 0.f;
	value[3] = 0.f;

	Eigen::VectorXf expectedValue = Eigen::VectorXf( 4 );
	expectedValue[0] = 1.f;
	expectedValue[1] = 1.f;
	expectedValue[2] = 1.f;
	expectedValue[3] = 1.f;

	Fitness fit = Fitness( value, expectedValue );

	ASSERT_GT( fit.totalDifference(), 0 );
}

TEST( Fitness_test, NegativeExpectedValue ) {
	Eigen::VectorXf value = Eigen::VectorXf( 4 );
	value[0] = 0.f;
	value[1] = 0.f;
	value[2] = 0.f;
	value[3] = 0.f;

	Eigen::VectorXf expectedValue = Eigen::VectorXf( 4 );
	expectedValue[0] = -1.f;
	expectedValue[1] = -1.f;
	expectedValue[2] = -1.f;
	expectedValue[3] = -1.f;

	Fitness fit = Fitness(value, expectedValue);

	ASSERT_GT( fit.totalDifference(), 0 );
}
