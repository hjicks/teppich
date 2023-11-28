typedef struct
{
	uint8 id;
	char *name;
	char *pass;
}user_t;

static user_t cuser;

static user_t adam =
{
	.id = 1,
	.name = "adam",
	.pass = "",
};
