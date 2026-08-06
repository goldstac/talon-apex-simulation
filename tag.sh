echo "Welcome To Tag"
echo "Enter Tag Version -->"
read version
git tag $version && git push origin $version