/* MD5 context. */

typedef	unsigned long	ulong;
typedef	unsigned char	uchar;

class	MD5 {
	ulong	state[4];	/* state (ABCD) */
	ulong	count[2];	/* number of bits, modulo 2^64 (lsb first) */
	uchar	buffer[64];	/* input buffer */

static	const	int	S[4][4];
static	const	ulong	ac[64];
static 	const	uchar 	PADDING[64];

	/** F, G, H and I are basic MD5 functions. */
static	ulong	F(ulong x, ulong y, ulong z) {
		return	(((x) & (y)) | ((~x) & (z)));
	}
static	ulong	G(ulong x, ulong y, ulong z) {
		return	(((x) & (z)) | ((y) & (~z)));
	}
static	ulong	H(ulong x, ulong y, ulong z) {
		return	((x) ^ (y) ^ (z));
	}
static	ulong	I(ulong x, ulong y, ulong z) {
		return	((y) ^ ((x) | (~z)));
	}
	/** ROTATE_LEFT rotates x left n bits. */
static	ulong	ROTATE_LEFT(ulong x, int n) {
		return	(((x) << (n)) | ((x) >> (32-(n))));
	}
	/** FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4.
	 *  Rotation is separate from addition to prevent recomputation.
	 */
static	void	FF(ulong &a, ulong b, ulong c, ulong d, ulong x, int s, ulong ac) {
		(a) += F ((b), (c), (d)) + (x) + (ac);
		(a) = ROTATE_LEFT ((a), (s));
		(a) += (b);
	}
static	void	GG(ulong &a, ulong b, ulong c, ulong d, ulong x, int s, ulong ac) {
		(a) += G ((b), (c), (d)) + (x) + (ac);
		(a) = ROTATE_LEFT ((a), (s));
		(a) += (b);
}
static	void	HH(ulong &a, ulong b, ulong c, ulong d, ulong x, int s, ulong ac) {
		(a) += H ((b), (c), (d)) + (x) + (ac);
		(a) = ROTATE_LEFT ((a), (s));
		(a) += (b);
	}
static	void	II(ulong &a, ulong b, ulong c, ulong d, ulong x, int s, ulong ac) {
		(a) += I ((b), (c), (d)) + (x) + (ac);
		(a) = ROTATE_LEFT ((a), (s));
		(a) += (b);
	}
	void	Transform(const uchar x[64]);
	void	Transform(const ulong x[16]);
static	void	Encode(uchar *output, const ulong *input, int len);
static	void	Decode(ulong *output, const uchar *input, int len);
	void	Init();
	void	Update(const uchar *input, int inputLen);
	void	Final(uchar digest[16]);
public:
	void	Data(const uchar *data, int len, uchar digest[16]);
	char	*HexString(const char *data, int len, char *buf);

};

