/**
 * is_divisible - checks if a number is divisible
 * @divisor: integer value.
 * @n: integer value.
 *
 * Return: 0 if not divisible, 1 if divisible
 */

int is_divisible(int n, int divisor)
{
	if (divisor <= 1)
		return (0);
	else if (n % divisor == 0)
		return (1);
	else
		return (is_divisible(n, divisor - 1));
}

/**
 * is_prime_number - function that returns 1 if the input integer
 * is a prime number, otherwise return 0.
 * @n: given input number.
 *
 * Return: 1 if the input integer is a prime number,
 * otherwise return 0.
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (!is_divisible(n, n - 1));
}
