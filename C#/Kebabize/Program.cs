using System;
using System.Collections.Generic;
using System.Text;

namespace Kebabize
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(camelCaseToKebabCase("isActiveInHierarchy"));
        }

        public static string camelCaseToKebabCase(string input)
        {
            StringBuilder kebabCaseStringBuilder = new();

            foreach (char inputCh in input)
            {
                if (char.IsUpper(inputCh))
                {
                    kebabCaseStringBuilder.Append('-')
                                          .Append(char.ToLower(inputCh));
                }
                else
                {
                    kebabCaseStringBuilder.Append(inputCh);
                }
            }

            return kebabCaseStringBuilder.ToString();
        }
    }
}
