#pragma once
class zh_stat {
public:
	zh_stat() {
		get = 0;
		put = 0;
		new_txn = 0;
		commit_txn = 0;
		
		get_counter = 0;
		put_counter = 0;
		new_txn_counter = 0;
		commit_txn_counter = 0;

		aborted = 0;

		index = 0;
		table_read = 0;
		table_write = 0;
		cc = 0;
	}
	void add_measurement(zh_stat *p, bool success) {
		if (success) {
			get += p->get;
			get_counter += p->get_counter;
			put += p->put;
			put_counter += p->put_counter;
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
	double get;
	double put;
	double new_txn;
	double commit_txn;

	int get_counter;
	int put_counter;
	int new_txn_counter;
	int commit_txn_counter;

	double aborted;

	double index;
	double table_read;
	double table_write;
	double cc;
};
