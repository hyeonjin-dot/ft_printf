//


// printf_u minus && printf_d minus

 if (num == 0 && ele->dot >= 1 && ele->num[1] <= 0)
 {
     while (ele->minus == 1 && ele->num[1] != 0 && ele->num[0]-- > 0)
         write(1, "0", 1);
     while (ele->num[0]-- > 0)
         write(1, " ", 1);
     if (i != -1)
         return (i);
     else
         return (0);
 }
  if (ele->minus == 5)
      ele->num[1] = len;
  if (ele->minus !=5 && ele->num[1] > (int)len) // d_minus는 ele->minus !=5 가 없음  
      ele->num[0] = ele->num[0] - ele->num[1];
  else
      ele->num[0] = ele->num[0] - len; // 여기까지 양수도 같음 단 5가 아니라 2  
  if (num < 0)
  {
      write(1, "-", 1);
      tmp++;
      len--;
      if (ele->minus == 5)
          ele->num[1]--;
  }
ele->num[1] = ele->num[1] - len;

// d & u
if (num == 0 && ele->dot != 0 && ele->num[1] < 1)
{
    while (ele->num[0]-- > 0)
        write(1, " ", 1);
    if (i != -1)
        return (i);
    else
        return (0);
}

