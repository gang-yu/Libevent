
struct op {
	enum {
		OP_OOPS,
		OP_QUIT,
		OP_HELP,
		OP_ADD,
		OP_DEL,
		OP_GET,
		OP_STEP,
		OP_UPDATE,
		OP_CHECK,
	} type;

	union {
		struct {
			char why[32];
		} oops;

		struct {
			unsigned id;
			timeout_t timeout;
		} add;

		struct {
			unsigned id;
		} del;

		struct {
			timeout_t time;
		} step, update;
	};
}; /* struct op */


struct op *parseop(struct op *, char *ln);


struct vops {
	void (*init)(struct timeout *, size_t);
	void (*add)(struct timeout *, timeout_t);
	void (*del)(struct timeout *);
	struct timeout *(*get)(void);
	void (*update)(timeout_t);
	void (*check)(void);
}; /* struct vops() */


