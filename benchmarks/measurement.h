#pragma once
class zh_stat {
public:
	zh_stat() {
		for (int i = 0; i < 5; i++) {
			prep[i] = 0;
			work[i] = 0;
			commit[i] = 0;
		}
		index = 0;
		table_read = 0;
		table_write = 0;
		cc = 0;
	}
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
	void add_measurement(zh_stat *p, bool success) {
		if (success) {
			get += p->get;
			put += p->put;
			new_txn += p->new_txn;
			commit_txn += p->commit_txn;
			index += p->index;
			table_read += p->table_read;
			table_write += p->table_write;
			cc += p->cc;
		} else {
			aborted += p->new_txn + p->commit_txn + p->get + p->put;
		}
	}
public:
	// order: new_order, delivery, payment, order_status, stock_level
	double prep[5]; // preparation
	double work[5]; // real work
	double commit[5]; // commit

	double get;
	double put;
	double new_txn;
	double commit_txn;

	double aborted;

	double index;
	double table_read;
	double table_write;
	double cc;
};
