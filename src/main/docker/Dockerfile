#Get ThingML (at a given commit) and compile it
FROM maven:3-jdk-8-slim

ARG SHA=e6d042d47ba6f77774a6141e2ef9909e36e0ae0e

COPY ./settings.xml settings.xml

RUN apt-get update && apt-get install -y unzip && rm -rf /var/lib/apt/lists/*
RUN curl --silent -O -J -L https://github.com/TelluIoT/ThingML/archive/$SHA.zip && unzip -qq ThingML-$SHA.zip -d . && rm ThingML-$SHA.zip

WORKDIR ThingML-$SHA

RUN mvn -q -s ../settings.xml -DskipTests clean install && mv compilers/official-network-plugins/target/*-jar-with-dependencies.jar /thingml.jar



FROM openjdk:8-jre-slim

COPY --from=0 thingml.jar thingml.jar

RUN chmod +x thingml.jar

ENTRYPOINT ["java", "-jar", "thingml.jar"]
CMD ["-h"]
