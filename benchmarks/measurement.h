#pragma once
class zh_stat {
public:
	double get_prep() {
		double sum = 0;
		for (int i = 0; i < 5; i++) sum += prep[i];
		return sum;
	}
	double get_work() {
		double sum = 0;
		for (int i = 0; i < 5; i++) sum += work[i];
		return sum;
	}
	double get_commit() {
		double sum = 0;
		for (int i = 0; i < 5; i++) sum += commit[i];
		return sum;
	}
public:
	// order: new_order, delivery, payment, order_status, stock_level
	double prep[5]; // preparation
	double work[5]; // real work
	double commit[5]; // commit
	double index;
	double table;
	double other;
};
