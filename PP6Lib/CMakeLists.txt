#add pp6lib as a library
add_library(pp6lib STATIC PP6Math.cpp PP6Math.hpp) 

add_library(ThreeVector STATIC ThreeVector.cpp ThreeVector.hpp)
target_link_libraries(ThreeVector pp6lib)

add_library(FourVector STATIC FourVector.cpp FourVector.hpp)
target_link_libraries(FourVector ThreeVector)

add_library(Particle STATIC Particle.cpp Particle.hpp)
target_link_libraries(Particle FourVector)

add_library(ParticleInfo STATIC ParticleInfo.cpp ParticleInfo.hpp)
target_link_libraries(ParticleInfo FileReader)
