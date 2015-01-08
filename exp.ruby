total_track_size = rand(200)
total_cylinders = rand(50)
cylinders = []
total_cylinders.times do
  cylinders.push(rand(total_track_size))
end
puts "./a.out #{total_track_size} #{total_cylinders} #{cylinders.join(' ')}"
exec "./a.out #{total_track_size} #{total_cylinders} #{cylinders.join(' ')}"
puts ""

