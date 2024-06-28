
#include "push_swap.h"

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}  // bu fonksiyon tekrarlananları bulmak için kontrol edilecek değer, tüm liste , kontrol başlanacak indeks, hep kendinden sonrakini kontrol edecek

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;   // negatif sayı ise kontrol edebilmek için int de taşmaması için
	char	**args;	

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');   //char olduğu için mesela "2 3 45 64 9" bazıldı o zaman bölüp bakıyor 2 3 45 şeklinde gönderse zaten sorun yok 
	else
	{
		i = 1;
		args = argv;   // eğer öyle bir durum zaten yoksa tüm argümanları direkt atıyorum args ye 
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);  //aldığım argümanları int türüne çeviriyorum 
		if (!ft_isnum(args[i]))   // numerik mi kontrol ediyorum
			ft_error("Error");
		if (ft_contains(tmp, args, i))    //tekraranmış mı onu kontrol et
			ft_error("Error");
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error("Error");
		i++;
	}
	if (argc == 2)
		ft_free(args);   // bu durumda splitte mallocla yer tahsis ettik ama aksi durumda sadece adresi işaret ettik bu yüzden bu aşaamada free yaptık
}
