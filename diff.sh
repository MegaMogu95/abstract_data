#!/bin/bash
./ft_containers > ft_out.txt
./std_containers > std_out.txt
diff ft_out.txt std_out.txt
