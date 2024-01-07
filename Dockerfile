FROM ubuntu:noble-20231221 AS build

# add build dependencies


# copy over files
WORKDIR /proj
COPY ./bfo.c .
COPY ./bfo.h .

# compile with appropriate flags


# FROM ubuntu:noble-20231221

# # copy over compiled program
# WORKDIR /proj
# COPY --from=build /bfo .

# # copy over shell command
# COPY ./exec.sh .
# RUN chmod +x exec.sh
