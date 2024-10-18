#include <cassert>

/// Вычисление объема куба, где len - длиина ребра куба
float calculate_value(float len) {
	return len * len * len;
}

/// Вычисление площади куба, где len - длиина ребра куба
float calculate_sqare(float len) {
	return 6 * len * len;
}

/// Тесты для проверки корректности программы
void test() {
	assert(calculate_value(2) == 8);
	assert(calculate_sqare(2) == 24);
	assert(calculate_value(5.6) == 175.616);
	assert(calculate_sqare(5.6) == 188.16);
	assert(calculate_value(3.2) == 32.768);
	assert(calculate_sqare(3.2) == 61.44);
}